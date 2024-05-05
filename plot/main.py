# import plotly.graph_objects as go

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import time

df = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_FORRO-K2-kyber_decaps.csv')

# Tamanho do gráfico em polegadas
plt.figure(figsize =(11, 6))

# Plot list
plot_list = [df.iloc[:,0]]
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)

# Adicionando Título ao gráfico
plt.title("Boxplot da base de dados Íris", loc="center", fontsize=18)
plt.xlabel("Comprimento das sépalas")
plt.ylabel("Tipos de Flores")

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