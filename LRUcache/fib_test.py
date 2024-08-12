import functools
import time
import LRUcache

# Timer wrapper
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
    def wrapper_cache(value):
        if lru.get(value) != None:
            return lru.get(value)
        else:
            res = func(value)
            lru.put(value, res)
            return res
    return wrapper_cache


# Comment out cache to compare.
@cache
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

test_fib(438)
