# Tried it in cpp but im only getting 17/18 XMASes in the the smallinput text case so I asked gpt to rewrite in python and idk why but it works

TEXT = 'XMAS'
L = len(TEXT)
S = 0
pg = []
directions = {
            'r': (0, 1),
            'R': (0, -1),
            'c': (1, 0),
            'C': (-1, 0),
            'p': (1, 1), 
            'P': (-1, -1), 
            'n': (1, -1), 
            'N': (-1, 1) 
    }


def main():
    global pg
    with open('inputs/input4.txt') as file:
        for line in file:
            linearr = list(line.strip())
            pg.append(linearr)
    itera()
    print(S)


def itera():
    for i in range(len(pg)):
        for j in range(len(pg[0])):
            poscheck(i, j)


def poscheck(y, x):
    global S, directions

    
    valid = is_valid(x, y)

    for orient, (dy, dx) in directions.items():
        if orient in valid:
            for i in range(L):
                n_x = x + i * dx
                n_y = y + i * dy
                if pg[n_y][n_x] != TEXT[i]:
                    break
            else:
                S += 1
 

def is_valid(x, y):
    yes = ''
    ncol = len(pg[0]) 
    nrow = len(pg) 

    for orient, (dy, dx) in directions.items():
        n_x = x + (L-1) * dx
        n_y = y + (L-1) * dy
        if 0 <= n_x < ncol and 0 <= n_y < nrow:
            yes += orient
    return yes


main()
# 2547