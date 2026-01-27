import os

# ========= CONFIG =========
ROOT_DIR = "."                     # run from CYBER-PHYSICAL-MICROGRID
OUTPUT_FILE = "combined_code.txt"

# File extensions to include
INCLUDE_EXT = {
    ".c", ".h", ".icd", ".yml", ".yaml",
    ".txt", ".md", ".json", ".cid"
}

# Directories to ignore completely
IGNORE_DIRS = {
    ".git",
    ".vscode",
    "__pycache__",
    "build",
    "libiec61850",
    "libmodbus",
    "pcc1"
}
# ==========================


def should_include(filename):
    name, ext = os.path.splitext(filename)
    return ext in INCLUDE_EXT or filename == "Dockerfile"


def main():
    with open(OUTPUT_FILE, "w", encoding="utf-8") as out:
        for root, dirs, files in os.walk(ROOT_DIR):
            # prune ignored directories
            dirs[:] = [d for d in dirs if d not in IGNORE_DIRS]

            for file in sorted(files):
                if not should_include(file):
                    continue

                path = os.path.join(root, file)
                rel_path = os.path.relpath(path, ROOT_DIR)

                out.write("=" * 80 + "\n")
                out.write(f"{rel_path}\n")
                out.write("=" * 80 + "\n")

                try:
                    with open(path, "r", encoding="utf-8", errors="ignore") as f:
                        out.write(f.read())
                except Exception as e:
                    out.write(f"[ERROR READING FILE: {e}]\n")

                out.write("\n\n")

    print(f"Combined code written to {OUTPUT_FILE}")


if __name__ == "__main__":
    main()
