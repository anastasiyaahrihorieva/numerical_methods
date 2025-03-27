import matplotlib.pyplot as plt
X = []
Y = []
parts =[]
with open('fact_eps.txt', 'r') as eps_parts_err:
    for line in eps_parts_err:
        row = line.split()
        X.append(float(row[0]))  
        Y.append(float(row[2])) 
        parts.append(int(row[1])) 

plt.semilogx(X, Y)
plt.title('фактическая ошибки от заданной точности')
plt.ylabel('фактическая ошибка')
plt.xlabel('точность')
plt.grid(True)  
plt.show()






