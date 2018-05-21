set(SHELL_SOURCES main.c parser.c exec.c)

add_executable(minishell ${SHELL_SOURCES})

install (TARGETS minishell DESTINATION bin/)
