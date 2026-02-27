from time import ticks_ms, ticks_diff
import os

def gregory_leibnitz(leib_num):
    calc = 0
    pos = True
    div_num = 1
    
    for _ in range(leib_num):
        if pos:
            calc += 1 / div_num    
            pos = False
        else:
            calc -= 1 / div_num
            pos = True
        div_num += 2
    return 4 * calc


start = ticks_ms()
result = gregory_leibnitz(10**8)
end = ticks_ms()

elapsed = ticks_diff(end, start)

print("Pi approximation:", result)
print("Time (microseconds):", elapsed)