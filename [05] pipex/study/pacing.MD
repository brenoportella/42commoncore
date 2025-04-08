### **Pré-Projeto: Preparação (Dia 0)**

- **Revisar o enunciado:**  
  Leia atentamente as especificações do PIPEX. Entenda os requisitos, as funções esperadas (como o uso de *pipe*, *fork*, *dup2*, etc.) e quais comportamentos seu programa deve ter.  
- **Organização:**  
  Reúna os materiais de apoio e anotações de aulas, exemplos e dicas da 42 sobre o tema.

---

### **Cronograma Detalhado**

#### **Dia 1 – Levantamento e Planejamento**  
- **Leitura aprofundada:**  
  Releia o enunciado e destaque cada requisito e funcionalidade necessária.  
- **Brainstorming e esboço:**  
  Anote ideias sobre como dividir o problema (por exemplo, separar o parsing dos comandos, a criação de processos, a implementação dos pipes).  
- **Defina metas diárias:**  
  Faça um plano simples no papel ou em uma ferramenta digital com o que deseja atingir em cada etapa.

#### **Dia 2 – Estruturação e Ambiente de Trabalho**  
- **Montagem do ambiente:**  
  Prepare seu ambiente de desenvolvimento (compilador, editor, e repositório Git para versionamento).  
- **Esboço do projeto:**  
  Estruture o diretório do projeto e crie os arquivos iniciais (ex.: *main.c*, *pipex.c*, *utils.c*).  
- **Mapeamento de funções:**  
  Liste as funções principais que você precisará implementar (ex.: função para executar comandos, função para gerenciar pipes, etc.).

#### **Dia 3 – Foco em Funções Básicas de Execução**  
- **Implementação inicial:**  
  Comece a desenvolver a função que chama `fork()` e `execve()` para executar um comando simples.  
- **Teste básico:**  
  Tente executar um comando simples e verifique se o processo filho está sendo criado corretamente.  
- **Comentários e anotações:**  
  Documente o código para facilitar futuras manutenções.

#### **Dia 4 – Manipulação de Pipes e Comunicação entre Processos**  
- **Implementação dos pipes:**  
  Conecte os processos criando a comunicação via pipe entre eles.  
- **Teste prático:**  
  Faça testes com dois comandos simples encadeados com pipe (ex.: `ls -l | grep <alguma_coisa>`).  
- **Depuração:**  
  Utilize prints ou ferramentas de depuração para identificar e corrigir possíveis erros de comunicação.

#### **Dia 5 – Integração com Arquivos (Input/Output)**  
- **Entrada e saída:**  
  Implemente a abertura de arquivos para leitura e escrita, conforme a especificação do projeto (ex.: uso de *open*, *read*, *write*).  
- **Testes de redirecionamento:**  
  Verifique se o arquivo de entrada está sendo lido corretamente e se os resultados dos comandos estão sendo gravados no arquivo de saída.

#### **Dia 6 – Fortalecimento de Funcionalidades e Gerenciamento de Erros**  
- **Trate casos de erro:**  
  Garanta que o programa lide bem com situações como arquivos inexistentes, comandos inválidos, problemas na criação de processos ou pipes falhando.  
- **Validação dos retornos:**  
  Adicione verificações de retorno de funções (ex.: de `fork`, `execve`, `pipe`, etc.) e trate os erros de forma adequada.

#### **Dia 7 – Testes Integrados e Debugging Final**  
- **Testes de integração:**  
  Faça testes completos que envolvam mais de um comando encadeado.  
- **Revisão de casos extremos:**  
  Teste entradas inesperadas para validar a robustez do programa.  
- **Refatoração inicial:**  
  Se necessário, refatore o código para melhorar a legibilidade e modularidade.

#### **Dia 8 – Otimização e Refatoração do Código**  
- **Aprimoramento:**  
  Revise a estrutura do código e otimize funções que estejam repetitivas ou que possam ser simplificadas.  
- **Aplicação de boas práticas:**  
  Garanta que a formatação, os comentários e a documentação estejam consistentes e claras.

#### **Dia 9 – Validação e Documentação Complementar**  
- **Testes finais:**  
  Realize testes abrangentes com diversos cenários para assegurar que o programa esteja conforme os requisitos.  
- **Documentação:**  
  Comece a escrever um README detalhado explicando como compilar, executar e testar o programa, além de listar as funcionalidades implementadas.

#### **Dia 10 – Revisão Geral e Preparação para a Entrega**  
- **Revisão de todo o código:**  
  Faça uma leitura completa do código, verifique padrões de código, e remova trechos desnecessários ou debug prints.  
- **Feedback:**  
  Se possível, peça para algum colega revisar ou teste o projeto.  
- **Checklist:**  
  Confirme que todos os requisitos do enunciado foram cumpridos.

#### **Dias 11 a 12 – Buffer e Ajustes Finais**  
- **Ajustes:**  
  Utilize esses dias para resolver problemas imprevistos ou adicionar pequenos detalhes sugeridos pela revisão.  
- **Testes repetitivos:**  
  Faça testes finais para ter certeza de que o programa está funcionando de forma robusta.

#### **Dia 13 – Submissão e Pós-Projeto**  
- **Preparação da entrega:**  
  Organize os arquivos finais, garanta que a documentação esteja completa e faça a submissão conforme as orientações da 42.  
- **Avaliação pessoal:**  
  Anote pontos que poderiam ser melhorados para projetos futuros e registre o que funcionou bem na sua organização.

---

### **Dicas para Maximizar o Aproveitamento do Tempo**

- **Rotina curta e consistente:**  
  Mesmo que sejam 1-2 horas por dia, a regularidade ajuda no avanço consistente do projeto.
- **Use o Git frequentemente:**  
  Faça commits com frequência para registrar seu progresso e facilitar a identificação de eventuais regressões.
- **Divida as tarefas maiores:**  
  Se algum dia parecer que a tarefa é muito extensa, subdivida-a em micro-tarefas (por exemplo, "testar comando A" e depois "testar comando B" dentro da mesma etapa).
- **Documente dúvidas:**  
  Mantenha um registro de dificuldades ou dúvidas que surgirem para que, em um momento posterior, você possa buscar soluções ou discutir com colegas.
- **Pausas e revisões:**  
  Planeje pequenas pausas para evitar sobrecarga e, ao final de cada sessão, faça uma revisão rápida do que foi alcançado e o que ainda falta.

---

Esse cronograma é apenas uma referência e pode ser adaptado conforme sua disponibilidade e o andamento do projeto. Boa sorte com o PIPEX e lembre-se de manter o foco, mesmo que o tempo seja limitado – cada pequena evolução diária é importante para o sucesso final do projeto!