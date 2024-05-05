# import plotly.graph_objects as go

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import time

df_aes = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_AES-K2.csv')
df_shake = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_SHAKE-K2.csv')
df_forro = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_FORRO-K2.csv')
df_xote = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_XOTE-K2.csv')

# Tamanho do gráfico em polegadas
plt.figure(figsize =(11, 6))

# Plot list gen_a
plot_list = [df_aes['gen_a'],df_shake['gen_a'],df_forro['gen_a'],df_xote['gen_a']]
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot gen_a", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

# Plot list keypair
plot_list = [df_aes['keypair'],df_shake['keypair'],df_forro['keypair'],df_xote['keypair']]
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Keygen", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes['encaps'],df_shake['encaps'],df_forro['encaps'],df_xote['encaps']]
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Encaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes['decaps'],df_shake['decaps'],df_forro['decaps'],df_xote['decaps']]
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Decaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

# import pandas as pd
# from datetime import datetime

# df = pd.read_csv('https://raw.githubusercontent.com/plotly/datasets/master/finance-charts-apple.csv')

# print(df)
# fig = go.Figure(data=[go.Candlestick(x=df['Date'],
#                 open=df['AAPL.Open'],
#                 high=df['AAPL.High'],
#                 low=df['AAPL.Low'],
#                 close=df['AAPL.Close'])])

# fig.show()

# df = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_FORRO-K2-gen_a.csv')

# print(df)

# # fig = go.Figure(data=[go.Candlestick(x=df['Date'],
# #                 open=df['AAPL.Open'],
# #                 high=df['AAPL.High'],
# #                 low=df['AAPL.Low'],
# #                 close=df['AAPL.Close'])])

# fig = go.Figure(data=[go.Candlestick(x=df.iloc[:, 0])])
# fig.show()