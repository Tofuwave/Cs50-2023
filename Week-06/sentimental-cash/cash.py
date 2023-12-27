from cs50 import get_float;

change = 0
count = 0

while change <= 0:
    change = get_float('Change owed: ')
    cents = round(change * 100)


while cents > 0:
    if cents >= 25:
        cents = cents - 25
        count = count + 1
    elif cents >= 10:
        cents = cents - 10
        count = count + 1
    elif cents >= 5:
        cents = cents - 5
        count = count + 1
    elif cents >= 1:
        cents = cents - 1
        count = count + 1
        
print(count)


