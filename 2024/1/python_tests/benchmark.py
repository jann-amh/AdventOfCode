import timeit
from main import main

def benchmark():

    iterations = 100000

    execution_time = timeit.timeit("main()", setup="from main import main", number=iterations)

    average_time = execution_time / iterations

    print(f"Total execution time for {iterations} iterations: {execution_time:.6f} seconds")
    print(f"Average execution time per iteration: {average_time:.6f} seconds")

if __name__ == "__main__":
    benchmark()
