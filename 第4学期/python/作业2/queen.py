def check(queue, x, y):
    for i in range(x):
        if queue[i] == y or abs(x - i) == abs(queue[i] - y):
            return True
    return False

def put(n, queue, col,ans1,ans2):
    global counter
    for i in range(n):
        if not check(queue, col, i):
            queue[col] = i
            if col == n - 1:    # 此时最后一个皇后摆放好了
                if(counter==0):
                    for i in range(n):
                        ans1[i]=queue[i]
                    counter=counter+1
                elif(counter==1):
                    for i in range(n):
                        ans2[i]=queue[i]
                    counter+=1
                else:
                    break
            else:
                put(n, queue, col + 1,ans1,ans2)

counter=0

def fun_queen(n,ans1,ans2):
    queue = [None for i in range(n)]
    put(n, queue, 0,ans1,ans2)
    return ans1,ans2