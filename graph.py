import matplotlib.pyplot as plt

def plot_from_file(filename):
    """
    Строит график по файлу со статистикой
    """
    x = []
    y = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                values = line.split()
                x_value = float(values[0])
                y_value = float(values[1])
                x.append(x_value)
                y.append(y_value)


    if x and y:
        plt.plot(x, y, marker='o')  
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.grid(True)
        plt.show()
    else:
        print("No data to plot.")


if __name__ == '__main__':
    filename = 'matrix_out\\matrix_statistic.txt'  
    plot_from_file(filename)
