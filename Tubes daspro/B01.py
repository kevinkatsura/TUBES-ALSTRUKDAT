def egcd(a, b): #extended fpb
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = egcd(b % a, a)
        return g, x - (b // a) * y, y
def modinv(a, m):   #modulo inverse
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m
def encrypt_block(m): #mengembalikan nilai modulo inverse dari m^e, n
    c = modinv(m**e, n)
    if c == None: print('No modular multiplicative inverse for block ' + str(m) + '.')
    return c
def encrypt_string(s): #menyatukan hasil encrypt block dalam sebuah string
    return ''.join([chr(encrypt_block(ord(x))) for x in list(s)])
def initialize():
    global p
    p=541
    global q
    q=547
    global n
    n=p*q
    global e
    e=293333
    global d
    d=145757

#Algoritma RSA
def enkripsi(pass1):
    initialize()
    enc = encrypt_string(pass1)

    return enc
