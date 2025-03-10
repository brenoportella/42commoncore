## roadmap
lidar com erros:
- [ ] arquivo não existe
- [ ] arquivo inválido
- [ ] comando inválido
- [ ] ...

funções shell a implementar:
- [ ] ls
- [ ] ...
<br><br>


## Estrutura:


Processo Pai: 
- inicializa os arquivos
- cria os pipes de comunicação
- gerencia processos filhos

Processo filho:
- cada filho executa um comando
- redirenciona os descritores

Fluxo:
- validação dos argumentos, quantidade
- validação e abertura dos arquivos de entrada e saida
- criar comunicação entre processos com pipe()
- o primeiro filho (chd1) redireciona o arquivo de entrada para a entrada padrão e a saída para a extremidade de escrita do pipe
- o segundo filho redireciona o arquivo de entrada para a extremidade de escrita do pipe e a saida padrão para o arquivo de saída.
- cada filho vai executar o comando com execve(). garantir env e path corretos de cada comando

- o processo pai espera os processos filhos acabarem (wait() waitpid()).

- fechar todos descritores (arquivo 1 e 2) adequadamente, e mensagens de erro exibidas no terminal.
<br><br>


## VERSÃO BÁSICA:

- um programa que execute apenas um programa, mas que já lide com arquivo_entrada e arquivo_saida, fork/execve

- depois implementar pipe para a comunicação entre os dois processos

- verificação de leaks (valgrind)
<br><br>

### Dicas
---
- fechar todos os arquivos que foram abertos com open()

- prestar atenção no que é duplicado no fork

- conferir os retornos de open(), pipe(), fork(), dup2(), execve() para saber tratar problemas