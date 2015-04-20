// zlib_test.c - a file for playing around with the zlib library!
// by Harrison Shoebridge!

#include <zlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif

#define CHUNK 16384

int compressInput(FILE *source, FILE *out, int level);

int main(int argc, char *argv[]) {
    assert(compressInput(stdin, stdout, Z_OK) == Z_OK);
    return EXIT_SUCCESS;
}

int compressInput(FILE *source, FILE *dest, int level) {
    int ret;
    int flush = Z_NO_FLUSH;
    unsigned int have;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];
    z_stream stream;
    
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;
    stream.opaque = Z_NULL;
    
    ret = deflateInit(&stream, level);
    if (ret != Z_OK) {
        return ret;
    }

    while (flush != Z_FINISH) {
        stream.avail_in = fread(in, 1, CHUNK, source);
        if (ferror(source)) {
            (void)deflateEnd(&stream);
            return Z_ERRNO;
        }

        flush = feof(source);
        if (feof(source)) {
            flush = Z_FINISH;
        }else {
            flush = Z_NO_FLUSH;
        }

        stream.next_in = in;

        while (stream.avail_out == 0) {
            stream.avail_out = CHUNK;
            stream.next_out = out;
            
            ret = deflate(&stream, flush);
            assert(ret != Z_STREAM_ERROR);
            have = CHUNK - stream.avail_out;
            if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
                (void)deflateEnd(&stream);
                return Z_ERRNO;
            }
        }

        assert(stream.avail_in == 0);
    }

    assert(ret == Z_STREAM_END);

    (void)deflateEnd(&stream);

    return Z_OK;
}
