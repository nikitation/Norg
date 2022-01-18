#ifndef TEST_H
#define TEST_H

#ifdef TEST_EXPORT
    #define test_EXPORT __declspec(dllexport)
#else
    #define test_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
    extern "C" {
#endif

test_EXPORT int f(int);

#ifdef __cplusplus
    }
#endif

#endif
