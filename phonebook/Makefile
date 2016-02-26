CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = phonebook_orig phonebook_opt phonebook_hash
all: $(EXEC)

SRCS_common = main.c
SRCS_hash   = main_hash.c

phonebook_orig: $(SRCS_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_opt: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_hash: $(SRCS_hash) phonebook_hash.c phonebook_hash.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
 		$(SRCS_hash) $@.c

run: $(EXEC)
	watch -d -t ./phonebook_orig


clean:
	$(RM) $(EXEC) *.o perf.*
