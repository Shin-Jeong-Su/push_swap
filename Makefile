NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
DEPFLAGS = -MMD -MP
RM = rm -rf

SRCS_NAME = my_deque\
			init\
			main
SRCS = $(addsuffix .c,$(SRCS_NAME))
OBJS = $(addsuffix .o,$(SRCS_NAME))
DEPS = $(addsuffix .d,$(SRCS_NAME))
LIB = ./libft/libft.a

all : $(OBJS) $(LIB)
	$(CC) $^ -o $(NAME)
-include $(DEPS)

d : $(LIB)
	$(CC) $(DEBUG) $^ $(SRCS) -o $(NAME)

$(LIB) :
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft
%.o : %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS) $(DEPS)