NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
DEPFLAGS = -MMD -MP
RM = rm -rf

SRCS_NAME = my_deque\
			my_deque2\
			utils\
			init\
			init_info\
			quick_sort\
			command\
			push_swap\
			sort_sml_a\
			sort_sml_b\
			main

SRCS = $(addsuffix .c,$(SRCS_NAME))
OBJS = $(addsuffix .o,$(SRCS_NAME))
DEPS = $(addsuffix .d,$(SRCS_NAME))
LIB = ./libft/libft.a

all : mandatory

mandatory : $(OBJS) $(LIB)
	@$(CC) $^ -o $(NAME)
	@touch mandatory
	@echo "push_swap made"
-include $(DEPS)

d : $(LIB)
	$(CC) $(DEBUG) $^ $(SRCS) -o $(NAME)

$(LIB) :
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft

%.o : %.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean : 
	@$(RM) $(OBJS) $(DEPS) mandatory
	@$(MAKE) -C ./libft clean
	@echo "cleaned"

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "fcleaned"

re : fclean all
