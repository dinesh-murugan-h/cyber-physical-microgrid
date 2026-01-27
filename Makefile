# Repo root Makefile
#
# PURPOSE
#   Simple control panel for microgrid devices.
#
# NAMING RULE
#   Each device is ONE compose service named:
#     <device>_device
#
# EXAMPLES
#   make build              # build ALL devices
#   make build pcc1         # build only pcc1_device
#   make build pcc1 gen1    # build pcc1_device + gen1_device
#
#   make up                 # start ALL devices
#   make up pcc1
#   make up pcc1 gen1
#
#   make stop pcc1
#   make logs gen1

COMPOSE_FILES = -f docker/compose.base.yml -f docker/compose.devices.yml
DC = docker-compose $(COMPOSE_FILES)

# Words the user typed after "make". Example: "build pcc1 gen1"
GOALS := $(MAKECMDGOALS)

# The first word is the command (build/up/stop/...). The rest are device names.
CMD   := $(firstword $(GOALS))
DEVS  := $(wordlist 2,$(words $(GOALS)),$(GOALS))

# Convert device names -> compose service names (<dev>_device)
SERVICES := $(foreach d,$(DEVS),$(d)_device)

.PHONY: build up stop down restart logs ps clean config $(DEVS)

# Dummy targets so "make up pcc1 gen1" won't error on unknown goals
$(DEVS):
	@:

config:
	$(DC) config

build:
	$(DC) build $(SERVICES)

up:
	$(DC) up -d $(SERVICES)

stop:
	$(DC) stop $(SERVICES)

down:
	$(DC) down

restart:
	$(DC) down
	$(DC) up -d $(SERVICES)

logs:
	$(DC) logs -f $(SERVICES)

ps:
	$(DC) ps

clean:
	$(DC) down --remove-orphans