CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3												\
			#-fsanitize=address,leak,undefined -fno-omit-frame-pointer

LIBDIR	=	libft

IFLAGS	=	-I$(LIBDIR) -IHEADERS
LIBS	=	$(LIBDIR)/libft.a

DFLAGS	=	-DDEBUG=0
LFLAGS	=	-lreadline


####################################===SOURCE FILES===####################################

LEXER_DIR		=	lexer
LEXER_FILES		=	tokenize.c			token_utils.c		free_token.c

PARSER_DIR		=	parser
PARSER_FILES	=	build_ast.c			free_ast.c			parse_primary.c			\
					parser_utils.c		parser_utils2.c		constructor.c			\
					print_ast.c			free_ast_utils.c	parse_primary_utils.c	\
					print_ast_utils.c

HEREDOC_DIR		=	heredoc
HEREDOC_FILES	=	open_heredocs.c		close_heredocs.c	heredoc_utils.c			\
					expand_heredoc.c

ENV_DIR			=	environment_variables
ENV_FILES		=	create_env.c						init_shell_env.c			\
					env_to_array.c						fetch_env_var_value.c		\
					fetch_env_var_value_n.c				set_env_var.c				\
					rm_env_var.c						filter_env_array.c			\
					print_filtered_env.c				print_formatted_env.c

ARGV_DIR		=	build_argv
ARGV_FILES		=	build_argv.c						create_wordlst.c			\
					create_wordsegs.c					expand_wordlst_env_var.c	\
					expand_wordlst_wildcard.c			get_matching_filenames.c	\
					match_wildcard.c												\
					free_wordseg.c						utils.c						\
					expanded_literal_utils.c

BUILTIN_DIR		=	builtins
BUILTIN_FILES	=	ft_echo.c			ft_cd.c			ft_pwd.c	ft_export.c		\
					ft_unset.c			ft_env.c		ft_exit.c

EXEC_DIR		=	execution
EXEC_FILES		=	execute_ast.c			simple_execute.c	binary_execute.c	\
					binary_execute_utils.c											\
					andor_execute.c			subshell_execute.c	pipe_execute.c		\
					pipe_utils.c													\
					process_redirection.c	save_io_fds.c		create_shell_child.c

SIG_DIR			=	signals
SIG_FILES		=	setup_signals.c		sigint_utils.c		sigquit_utils.c			\
					reset_signals.c
MODULES			=	LEXER PARSER HEREDOC ENV ARGV BUILTIN EXEC SIG
$(foreach M,$(MODULES), $(eval $(M)_SRCS = $(addprefix $($(M)_DIR)/, $($(M)_FILES))))

SRCDIR			=	SRCS
SRCFILES		=	main.c				clean_exit.c
SRCS			=	$(addprefix $(SRCDIR)/, $(SRCFILES) 							\
											$(foreach M,$(MODULES), $($(M)_SRCS)))

##########################################################################################


OBJDIR	=	OBJS
OBJS	=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

NEEDS_REBUILD_CMD	:=																\
	for src in $(SRCS); do															\
		obj="$$(echo "$$src" | sed 's|^$(SRCDIR)|$(OBJDIR)|')";						\
		obj="$${obj%.c}.o";															\
		if [ ! -f "$$obj" ] || [ "$$src" -nt "$$obj" ]; then echo "$$src"; fi;		\
	done
NEEDS_REBUILD 	:=	$(shell $(NEEDS_REBUILD_CMD))
SRCTOTAL		:=	$(words $(NEEDS_REBUILD))
SRCNUM			:=	0

RESET		=	\033[0m
BOLD		=	\033[1m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
ORANGE		=	\033[38;5;208m
YLLWGRN		=	\033[38;2;150;255;25m
PREVLINE	=	\033[A
RMLINE		=	\r\033[K


#########################################################################################

NAME	=	minishell

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LFLAGS) -o $(NAME)
	@printf "$(RMLINE)$(BOLD)$(YELLOW)$(NAME) successfully compiled\n$(RESET)"

$(LIBS):
	@make -s -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@
	@$(eval SRCNUM := $(shell expr $(SRCNUM) + 1))
	@$(eval CALCPERCENT := $(shell echo "scale=4; $(SRCNUM) / $(SRCTOTAL) * 100" | bc))
	@$(eval PERCENT := $(shell printf "%.0f" $(CALCPERCENT)))
	@if [ $(SRCNUM) -gt 1 ]; then printf "$(PREVLINE)\r"; fi;
	@printf "$(BOLD)Compiling $(NAME): ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@if [ $(PERCENT) -ge 5 ]; then printf "$(GREEN)%0.s#" $(shell seq 1 $(PROGRESS)); fi;
	@$(eval CALCPADS := $(shell expr 20 - $(PROGRESS)))
	@if [ $(PERCENT) -lt 100 ]; then printf "$(RESET)$(BOLD)%0.s-" $(shell seq 1 $(CALCPADS)); fi;
	@printf "$(RESET)$(BOLD)] "
	@if [ $(PERCENT) -lt 25  ]; then	\
		printf "$(RED)";				\
	elif [ $(PERCENT) -lt 50 ]; then	\
		printf "$(ORANGE)";				\
	elif [ $(PERCENT) -lt 75 ]; then	\
		printf "$(BOLD)$(YELLOW)";		\
	elif [ $(PERCENT) -lt 100 ]; then	\
		printf "$(BOLD)$(YLLWGRN)";		\
	else								\
		printf "$(BOLD)$(GREEN)"; fi;
	@printf "%d%% $(RESET)\n" $(PERCENT)
	@printf "Compiling %-34s" $(notdir $@)

clean:
	@make fclean -s -C $(LIBDIR)
	@printf "$(RED)"
	@if [ -d $(OBJDIR) ]; then						\
		rm -rf $(OBJDIR);							\
		printf "Removed $(NAME) OBJS directory\n";	\
	else											\
		printf "$(NAME) objects not found\n"; fi;
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)"
	@if [ -f $(NAME) ]; then				\
		rm -f $(NAME);						\
		printf "Removed $(NAME)\n";			\
	else									\
		printf "$(NAME) not found\n"; fi;
	@printf "$(RESET)"

re: fclean
	@make -s all

bonus: all

.PHONY: all clean fclean re bonus
