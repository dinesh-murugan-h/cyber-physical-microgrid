# Makefile (repo root)
#
# PURPOSE
#   Short commands for building and running your Modbus server stack.
#
# WHY docker-compose (hyphen) not "docker compose" (space)?
#   On Raspberry Pi OS you installed docker-compose as a standalone binary.
#   The V2 plugin command "docker compose" may not exist.

COMPOSE = docker-compose -f docker/mg_pair_c/docker-compose.modbus.yml

# -------------------------
# Build (rebuild image after C code / regmap.h changes)
# -------------------------
build:
	$(COMPOSE) build

# -------------------------
# Run servers in background (-d detached)
# -------------------------
run:
	$(COMPOSE) up -d

# -------------------------
# Stop servers but keep containers (fast restart)
# -------------------------
stop:
	$(COMPOSE) stop

# -------------------------
# Stop + remove containers (clean slate)
# -------------------------
down:
	$(COMPOSE) down

# -------------------------
# Follow logs for ALL services
# -------------------------
logs:
	$(COMPOSE) logs -f

# -------------------------
# Follow logs for ONE specific service (OPTION A)
#
# Usage examples:
#   make logs-dev SERVICE=dev1_modbus
#   make logs-dev SERVICE=dev2_modbus
#   make logs-dev SERVICE=dev3_modbus
# -------------------------
logs-dev:
	$(COMPOSE) logs -f $(SERVICE)

# -------------------------
# Clean restart (remove containers, then start again)
# -------------------------
restart:
	$(COMPOSE) down
	$(COMPOSE) up -d

# -------------------------
# Convenience: show running containers in this stack
# -------------------------
ps:
	$(COMPOSE) ps
