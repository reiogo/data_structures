import functools
import time
import LRUcache

// Timer wrapper
def timer(func):
    @functools.wraps(func)
    def wrapper_timer(*args, **kwargs):
        start_time = time.perf_counter()
        res = func(*args, **kwargs)
        end_time = time.perf_counter()
        run_time = end_time - start_time
        print(f"Finished {func.__name__}() in {run_time:.8f} secs")
        return res
    return wrapper_timer


def cache(func):
    lru = LRUcache.Lru(3)
    def fib_with_cache(value, prev, prevPrev):

        prev = lru.get(value - 1)
        prevPrev = lru.get(value - 2)

        res = func(value, prev, prevPrev)
        lru.put(value, res)

        return res

    return fib_with_cache



@cache
def fibWithCache(value, prev = None, prevPrev = None):

    if value == 0:
        return 0

    elif value == 1:
        return 1

    if prev and prevPrev:
        return prev + prevPrev
    elif prev:
        return prev + fibWithCache(value - 2, None, None)
    elif prevPrev:
        return fibWithCache(value - 1, None, None) + prevPrev
    else:
        return fibWithCache(value - 1, None, None) + fibWithCache(value - 2, None, None)
        

def fib(value):

    if value == 0:
        return 0

    elif value == 1:
        return 1

    return fib(value - 1) + fib(value - 2)
        


@timer
def test_fib (num):
    result = fib(num)
    print("answer: ", result);
    return result


@timer
def test_fib_with_cache (num):
    result = fibWithCache(num, None, None)
    print("answer: ", result);
    return result


def compare (num):
    test_fib(num)
    test_fib_with_cache(num)

compare(38)





    

