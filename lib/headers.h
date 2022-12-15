#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct ResolverBuilder ResolverBuilder;

typedef struct Buffer {
  uint8_t *data;
  int len;
} Buffer;

struct Buffer invoke(const char *client_ptr, const char *uri, const char *method, const char *args);

const char *create_client(const char *resolver_ptr);

const char *create_resolver(void);

struct ResolverBuilder *create_builder(void);

const char *create_static_resolver(const char *from, const char *to);

void add_static_resolver(struct ResolverBuilder *builder, const char *resolver);

const char *build_resolver(struct ResolverBuilder *builder);
