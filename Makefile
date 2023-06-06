# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 14:21:23 by ppaquet           #+#    #+#              #
#    Updated: 2023/04/12 14:21:24 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define TITLE
██████  ██    ██ ███████ ██   ██         ███████ ██     ██  █████  ██████
██   ██ ██    ██ ██      ██   ██         ██      ██     ██ ██   ██ ██   ██
██████  ██    ██ ███████ ███████         ███████ ██  █  ██ ███████ ██████
██      ██    ██      ██ ██   ██              ██ ██ ███ ██ ██   ██ ██
██       ██████  ███████ ██   ██ ███████ ███████  ███ ███  ██   ██ ██
endef
export TITLE

#==================================================================================================|
#---< PUSH_SWAP >----------------------------------------------------------------------------------|
#                                 VARIABLES                                                        |
#==================================================================================================|

# ---------------------------------------------------------------------------------< EXECUTABLE >---
NAME := push_swap
NAME_BONUS := checker

# ----------------------------------------------------------------------------------< COMPILING >---
CC := gcc
CFLAGS := -g -Wall -Wextra -Werror

# --------------------------------------------------------------------------------------< OTHER >---
RM := rm -rf
MK := make

# -------------------------------------------------------------------------------------< COLORS >---
WTH := \033[0m
GRN := \033[0;32m
RED := \033[0;31m
YEL := \033[0;33m
BLU := \033[0;34m
BLD := \033[1m

# -----------------------------------------------------------------------------------< INCLUDES >---
INCLUDES_PATH := includes/
INCL := -I $(INCLUDES_PATH)

LIBFT := libft/libft.a

# ------------------------------------------------------------------------------------< SOURCES >---
SRCS_PATH := srcs/
SRCS_FILES := \
	main.c\
	ps_checks.c\
	ps_free.c\
	ps_list_utils.c \
	\
	ps_move_double.c\
	ps_move_master.c\
	ps_move_push.c\
	ps_move_rotate.c\
	\
	ps_numeric.c \
	ps_parsing.c \
	ps_segmentation.c\
	\
	ps_sort_big_utils.c\
	ps_sort_big.c\
	ps_sort_mid.c\
	ps_sort_small.c\
	ps_sort_utils.c\
	\
	push_swap.c\

SRCS := $(addprefix $(SRCS_PATH), $(SRCS_FILES))


# -------------------------------------------------------------------------------------< HEADER >---
HEADER_FILE := push_swap.h

HEADER := $(addprefix $(INCLUDES_PATH), $(HEADER_FILE))

# ------------------------------------------------------------------------------------< OBJECTS >---
OBJS_PATH := objs/
OBJS := $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))


# ------------------------------------------------------------------------------------< BONUS >---
BONUS_SRCS_FILES := \
	checker.c\

BONUS_OBJS := $(addprefix bonus/$(OBJS_PATH), $(BONUS_SRCS_FILES:.c=.o))

BONUS_PATH := bonus/
BONUS_SRCS_FILES := \
	checker.c\

BONUS_OBJS_LIST := \
	$(OBJS_PATH)ps_checks.o\
	$(OBJS_PATH)ps_free.o\
	$(OBJS_PATH)ps_list_utils.o\
	$(OBJS_PATH)ps_move_double.o\
	$(OBJS_PATH)ps_move_push.o\
	$(OBJS_PATH)ps_move_rotate.o\
	$(OBJS_PATH)ps_numeric.o\
	$(OBJS_PATH)ps_segmentation.o\
	$(OBJS_PATH)ps_parsing.o\


#==================================================================================================|
#---< PUSH_SWAP >----------------------------------------------------------------------------------|
#                                    RULES                                                         |
#==================================================================================================|

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCL)
	@echo "\t\t$(WTH)push_swap executable _______________ $(GRN)$(BLD)[CREATED]"
	clear
	@echo "\n$(GRN)$(BLD)OKAY, LET'S\n"
	@echo "$$TITLE\n"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH) 2> /dev/null || true

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(BONUS_PATH)$(OBJS_PATH)%.o: $(BONUS_PATH)$(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@echo "\n$(GRN)$(BLD)[COMPILING]\n"
	@$(MK) -C libft all

clean:
	@echo "\n$(RED)$(BLD)[DELETING]"
	@$(RM) $(OBJS_PATH)
	@$(MK) -C libft clean
	@echo "\t\t$(WTH)push_swap objects __________________ $(RED)$(BLD)[DELETED]"

fclean: clean
	@$(RM) $(NAME)
	@$(MK) -C libft fclean
	@echo "\t\t$(WTH)push_swap executable _______________ $(RED)$(BLD)[DELETED]"

################################################################################
bonus: $(LIBFT) $(NAME) $(BONUS_PATH)$(OBJS_PATH) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJS) $(BONUS_OBJS_LIST) $(LIBFT) $(INCL)
	@echo "\t\t$(WTH)checker executable _________________ $(GRN)$(BLD)[CREATED]"

$(BONUS_PATH)$(OBJS_PATH):
	@mkdir -p $(BONUS_PATH)$(OBJS_PATH) 2> /dev/null || true
	
bonusclean: fclean
	@$(RM) $(BONUS_PATH)$(OBJS_PATH)
	@$(RM) $(NAME_BONUS)
	@$(RM) checker.dSYM
	@echo "\t\t$(WTH)checker executable _________________ $(RED)$(BLD)[DELETED]"
################################################################################

re: bonusclean fclean clean+ all

#-------------------------------------------------------------------------------------< TESTERS >---
norm:
	clear
	@echo "$(GRN)$(BLD)[NORMINETTE - LIBFT SOURCE FILES]$(WTH)"
	@norminette -R CheckForbiddenSourceHeader libft/srcs | awk '{ printf("%60s\n", $$0) }'
	@echo "\n$(GRN)$(BLD)[NORMINETTE - PUSH_SWAP SOURCE FILES]$(WTH)"
	@norminette -R CheckForbiddenSourceHeader $(SRCS_PATH) | awk '{ printf("%60s\n", $$0) }'
	@norminette -R CheckForbiddenSourceHeader bonus/ | awk '{ printf("%60s\n", $$0) }'
	@echo "\n$(GRN)$(BLD)[NORMINETTE - INCLUDES]$(WTH)"
	@norminette -R CheckDefine $(INCLUDES_PATH) | awk '{ printf("%60s\n", $$0) }'
	@norminette -R CheckDefine libft/$(INCLUDES_PATH) | awk '{ printf("%60s\n", $$0) }'

################################################################################

testload: all testclean
	@git clone https://github.com/LeoFu9487/push_swap_tester.git > /dev/null 2>&1 &&\
	clear &&\
	cd push_swap_tester &&\
	for ((i=1; i<=500; i++)); do \
		bash loop.sh $$i 1; \
		if [[ $$i -eq 500 ]]; then \
			break; \
		fi; \
	done
	clear
	@echo "\n$(YEL)$(BLD)[TESTS FINISHED]\n"

test500: all testclean
	@git clone https://github.com/LeoFu9487/push_swap_tester.git > /dev/null 2>&1 &&\
	clear &&\
	cd push_swap_tester &&\
	bash loop.sh 500 100
	@echo "\n$(YEL)$(BLD)[TESTS FINISHED]\n"

test100: all testclean
	@git clone https://github.com/LeoFu9487/push_swap_tester.git > /dev/null 2>&1 &&\
	clear &&\
	cd push_swap_tester &&\
	bash loop.sh 100 100
	@echo "\n$(YEL)$(BLD)[TESTS FINISHED]\n"

tester: all testclean
	@git clone https://github.com/LeoFu9487/push_swap_tester.git > /dev/null 2>&1 &&\
	clear &&\
	cd push_swap_tester &&\
	bash basic_test.sh &&\
	clear

################################################################################

visualizer: all
	clear
	@echo "\n$(GRN)$(BLD)[LAUNCHING VISUALIZER]" && sleep 3
	clear
	@./push_swap_visualizer/build/bin/visualizer

visinstall: all brew
	clear
	@echo "\n$(GRN)$(BLD)[INSTALLING VISUALIZER]\n\n \
		$(WTH)This may take several minutes. Please be patient.\n"
	@git clone https://github.com/o-reo/push_swap_visualizer > /dev/null 2>&1 && \
	cd push_swap_visualizer && \
	mkdir -p build && \
	cd build && \
	cmake .. > /dev/null 2>&1 && \
	make > /dev/null 2>&1 &&\
	clear
	cd ../..
	@$(MK) visualizer

brew: 
	clear
	@echo "\n$(GRN)$(BLD)[UPDATING BREW]" && sleep 2
	@brew install cmake > /dev/null 2>&1
################################################################################

testclean:
	clear
	@$(RM) push_swap_tester
	@echo "$(RED)$(BLD)\n[TESTER DELETED]\n" && sleep 2
	clear

visclean:
	clear
	@$(RM) push_swap_visualizer
	@echo "$(RED)$(BLD)\n[VISUALIZER DELETED]\n"
	@sleep 2 && clear

backup:
	clear
	@echo "\n$(BLD)[BACKING UP PUSH_SWAP]\n"
	@tar -czvf backup_$(shell date +%Y%m%d_%H%M%S).tar.gz ./* > /dev/null 2>&1
	@mv backup_$(shell date +%Y%m%d_%H%M%S).tar.gz ~/Desktop/
	@sleep 4 && clear
	@echo "\n$(GRN)$(BLD)[PUSH_SWAP BACKUP NOW LOCATED ON DESKTOP]\n"

clean+: fclean visclean testclean bonusclean
	@$(RM) .vscode
	@$(RM) *.ini
	@$(RM) checker_Mac
	@$(RM) checker.dSYM
	@$(RM) push_swap.dSYM
	clear

title:
	@echo "$$TITLE"

help:
	@grep -E '^[a-zA-Z0-9_-]+:.*' Makefile | awk -F ':' '{print $$1}' | awk '{ printf("%60s\n", $$0) }'

.PHONY: all clean fclean re
