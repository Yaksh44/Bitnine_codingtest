import keyboard as key
import msvcrt

s = ''  
running = True
while running:
    key = msvcrt.getch()
    if key == b'\x1b' or key == b'0':
        print('You pressed escape or the number zero')
        quit()
    s = input("Enter the string: ")
    op = 0
    stack = []
    sign = 1
    result = 0
    for i in s:
        if i.isdigit():
            op = (op * 10) + int(i)
        elif i == '+':
            result += sign * op
            sign = 1
            op = 0
        elif i == '-':
            result += sign * op
            sign = -1
            op = 0
        elif i == '(':
            stack.append(result)
            stack.append(sign)
            sign = 1
            result = 0
        elif i == ')':
            result += sign * op
            result *= stack.pop()
            result += stack.pop()
            op = 0
        if result + sign * op > 100000000:
            raise Exception("The number can't go up than 10^7")
    print(result + sign * op)