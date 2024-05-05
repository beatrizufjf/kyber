# import plotly.graph_objects as go

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import time

############## K=2 ################
df_aes_k2 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_AES-K2.csv')
df_shake_k2 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_SHAKE-K2.csv')
df_forro_k2 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_FORRO-K2.csv')
df_xote_k2 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_XOTE-K2.csv')

# Plot list gen_a
plot_list = [df_aes_k2['gen_a'],df_shake_k2['gen_a'],df_forro_k2['gen_a'],df_xote_k2['gen_a']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot gen_a", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

# Plot list keypair
plot_list = [df_aes_k2['keypair'],df_shake_k2['keypair'],df_forro_k2['keypair'],df_xote_k2['keypair']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Keygen", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes_k2['encaps'],df_shake_k2['encaps'],df_forro_k2['encaps'],df_xote_k2['encaps']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Encaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes_k2['decaps'],df_shake_k2['decaps'],df_forro_k2['decaps'],df_xote_k2['decaps']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Decaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()


############## K=3 ################
df_aes_k3 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_AES-K3.csv')
df_shake_k3 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_SHAKE-K3.csv')
df_forro_k3 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_FORRO-K3.csv')
df_xote_k3 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_XOTE-K3.csv')

# Plot list gen_a
plot_list = [df_aes_k3['gen_a'],df_shake_k3['gen_a'],df_forro_k3['gen_a'],df_xote_k3['gen_a']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot gen_a", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

# Plot list keypair
plot_list = [df_aes_k3['keypair'],df_shake_k3['keypair'],df_forro_k3['keypair'],df_xote_k3['keypair']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Keygen", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes_k3['encaps'],df_shake_k3['encaps'],df_forro_k3['encaps'],df_xote_k3['encaps']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Encaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes_k3['decaps'],df_shake_k3['decaps'],df_forro_k3['decaps'],df_xote_k3['decaps']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Decaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()


############## K=4 ################
df_aes_k4 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_AES-K4.csv')
df_shake_k4 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_SHAKE-K4.csv')
df_forro_k4 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_FORRO-K4.csv')
df_xote_k4 = pd.read_csv('../NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/results/RESULTS_XOTE-K4.csv')

# Plot list gen_a
plot_list = [df_aes_k4['gen_a'],df_shake_k4['gen_a'],df_forro_k4['gen_a'],df_xote_k4['gen_a']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot gen_a", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

# Plot list keypair
plot_list = [df_aes_k4['keypair'],df_shake_k4['keypair'],df_forro_k4['keypair'],df_xote_k4['keypair']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Keygen", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes_k4['encaps'],df_shake_k4['encaps'],df_forro_k4['encaps'],df_xote_k4['encaps']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Encaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()

plot_list = [df_aes_k4['decaps'],df_shake_k4['decaps'],df_forro_k4['decaps'],df_xote_k4['decaps']]
plt.figure(figsize =(11, 6))
bplots = plt.boxplot(plot_list,  vert = 1, patch_artist = False)
# Adicionando Título ao gráfico
plt.title("Boxplot Decaps", loc="center", fontsize=18)
plt.xticks([1, 2, 3, 4], ['AES', 'SHAKE', 'FORRO', 'XOTE'])
plt.xlabel("Algorithm")
plt.ylabel("Cycles/ticks")
plt.show()