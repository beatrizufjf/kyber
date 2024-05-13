# import plotly.graph_objects as go

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import time

folderpath = "figures/"
csvpath = "../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/"
figures_format = "png"
# figures_format = "eps"

all_algs = ['AES', 'SHAKE', 'FORRO', 'XOTE']
print_algs = ['SHAKE', 'FORRO', 'XOTE']
list_count = list(range(1, len(print_algs)+1))
print(list_count)

funcs = ['xof_absorb', 'xof_squeeze', 'prf', 'kdf', 'gen_a', 'keypair', 'encaps', 'decaps']
primitive_funcs = ['xof_absorb', 'xof_squeeze', 'prf', 'kdf']

for func in funcs:
    # print(f'Plotting k = {k}')
    fig, axs = plt.subplots(nrows=1, ncols=3, sharex=False, figsize=(15, 4))
    for i,k in enumerate([2, 3, 4]):
        plot_list = []
        
        for cur_alg in all_algs:
            if(cur_alg in print_algs):
                if(func in primitive_funcs):
                    df = pd.read_csv(csvpath + 'RESULTS_PRIMITIVES_' + cur_alg + '-K' + str(k) + '.csv')
                else:
                    df = pd.read_csv(csvpath + 'RESULTS_' + cur_alg + '-K' + str(k) + '.csv')
                plot_list.append(df[func])
                print(f"Median of {cur_alg}-K{k}-{func}: {df[func].median()}")

        # plt.figure(figsize =(11, 6))
        bplots = axs[i].boxplot(plot_list, vert = 1, patch_artist = False, labels=print_algs, widths = .5)
        # Adicionando Título ao gráfico
        axs[i].set_title("K: " + str(k), loc="center", fontsize=18)
        # plt.xticks(list_count, print_algs)
        # axs[i].yticks(fontsize=18)
        # axs[0].xlabel("Algorithm")
        # axs[0].set_ylabel("Cycles/ticks")
        # ax0.savefig(folderpath + func + '-K' + str(k) + '.' + figures_format, format=figures_format)
        # if(i == 0):
    
        axs[i].tick_params(axis='both', which='major', labelsize=18)
        axs[i].ticklabel_format(style='sci', axis='y', scilimits=(0,0), useMathText=True)

    axs[0].set_ylabel("Cycles/ticks", fontsize=18)
    # for ax in axs.flat:
    #     ax.set(xlabel='x-label', ylabel='y-label')
        
    # fig.text(0.5, 0.04, 'common X', ha='center')
    # fig.text(0.1, 0.5, 'common Y', va='center', rotation='vertical')
    
    # fig.suptitle(func)
    fig.savefig(folderpath + func + '.' + figures_format, format=figures_format)
    # plt.show()
    
