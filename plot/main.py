# import plotly.graph_objects as go

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import time

folderpath = "figures/"
figures_format = "png"
# figures_format = "eps"

all_algs = ['AES', 'SHAKE', 'FORRO', 'XOTE']
print_algs = ['SHAKE', 'FORRO', 'XOTE']
list_count = list(range(1, len(print_algs)+1))
print(list_count)

for k in [2, 3, 4]:
    print(f'Plotting k = {k}')
    for func in ['gen_a', 'keypair', 'encaps', 'decaps']:
        plot_list = []
        for cur_alg in all_algs:
            if(cur_alg in print_algs):
                df = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_' + cur_alg + '-K' + str(k) + '.csv')
                plot_list.append(df[func])
                print(f"Median of {cur_alg}-K{k}-{func}: {df[func].median()}")
        plt.figure(figsize =(11, 6))
        bplots = plt.boxplot(plot_list, vert = 1, patch_artist = False, labels=print_algs)
        # Adicionando Título ao gráfico
        plt.title("Boxplot " + func, loc="center", fontsize=18)
        # plt.xticks(list_count, print_algs)
        plt.xlabel("Algorithm")
        plt.ylabel("Cycles/ticks")
        plt.savefig(folderpath + func + '-K' + str(k) + '.' + figures_format, format=figures_format)
        # plt.show()