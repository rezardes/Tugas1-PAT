#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <sys/stat.h>

#include <stdlib.h>

#include <fcntl.h>
#include <err.h>

#include <event2/event.h>

#include <evhttp.h>

void generic_handler(struct evhttp_request *req, void *arg)
{
    struct evbuffer *buf;
    int fd = -1;
    buf = evbuffer_new();
    
    if (buf == NULL)
        err(1, "failed to create response buffer");

    if ((fd = open("tes1.html", O_RDONLY)) < 0) {
			perror("open");
			//goto err;
    }

    evbuffer_add_file(buf, fd, 0, 600);
    //evbuffer_add_printf(buf, "<!DOCTYPE html><html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>", evhttp_request_uri(req));
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
}

void generic_handler_file(struct evhttp_request *req, void *arg, 
                        const char* filename, int filesize)
{
    struct evbuffer *buf;
    int fd = -1;
    buf = evbuffer_new();
    
    if (buf == NULL)
        err(1, "failed to create response buffer");

    if ((fd = open(filename, O_RDONLY)) < 0) {
			perror("open");
			//goto err;
    }

    evbuffer_add_file(buf, fd, 0, filesize);
    //evbuffer_add_printf(buf, "<!DOCTYPE html><html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>", evhttp_request_uri(req));
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
}

void tes1_handler(struct evhttp_request *req, void *arg)
{
    generic_handler_file(req, arg, "tes1.html", 600);
}

void tes2_handler(struct evhttp_request *req, void *arg)
{
    generic_handler_file(req, arg, "tes2.html", 20100);
}

int main(int argc, char **argv)
{
    struct evhttp *httpd;
    event_init();
    httpd = evhttp_start("0.0.0.0", 8003);
    /* Set a callback for requests to "/specific". */
    evhttp_set_cb(httpd, "/tes1", tes1_handler, NULL);
    evhttp_set_cb(httpd, "/tes2", tes2_handler, NULL);

    /* Set a callback for all other requests. */
    //evhttp_set_gencb(httpd, generic_handler, NULL);

    event_dispatch();    /* Not reached in this code as it is now. */
    evhttp_free(httpd);
    
    return 0;
}