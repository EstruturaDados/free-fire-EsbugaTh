# 🏗️ Torre de Fuga — Desafio Final de Algoritmos

Este projeto foi desenvolvido como parte do desafio final da disciplina de Algoritmos. Ele simula a montagem de uma torre de resgate em um jogo de sobrevivência, onde o jogador precisa organizar e buscar componentes com base em diferentes estratégias de ordenação e busca.

---

## 🎯 Objetivo

Criar um sistema interativo em C que permita:

- Cadastrar até 20 componentes da torre de fuga.
- Ordenar os componentes por diferentes critérios (nome, tipo ou prioridade).
- Realizar busca binária por um componente-chave.
- Medir o desempenho dos algoritmos de ordenação (tempo e número de comparações).
- Exibir os componentes organizados para montagem da torre.

---

## 🧱 Estrutura dos Componentes

Cada componente possui:

- `nome` (ex: "chip central")
- `tipo` (ex: "controle", "suporte", "propulsão")
- `prioridade` (int de 1 a 10)

---

## ⚙️ Funcionalidades

- **Cadastro de componentes** com `fgets` para segurança.
- **Ordenação por:**
  - Nome → Bubble Sort
  - Tipo → Insertion Sort
  - Prioridade → Selection Sort
- **Busca binária** por nome (após ordenação por nome).
- **Medição de desempenho**:
  - Número de comparações
  - Tempo de execução com `clock()`
- **Interface interativa** com menu amigável.

---

## 🖥️ Como compilar e executar

### Pré-requisitos:
- Compilador C (como `gcc`)

### Passos:

```bash
# 1. Compile o programa
gcc torre_fuga.c -o torre_fuga

# 2. Execute o programa
./torre_fuga


📦 torre-fuga
 ┣ 📄 torre_fuga.c         # Código-fonte principal
 ┗ 📄 README.md            # Este arquivo

 🧠 Aprendizados
Este projeto consolida os seguintes conceitos:
• 	Implementação de algoritmos clássicos de ordenação.
• 	Aplicação de busca binária em vetores ordenados.
• 	Modularização de código em C.
• 	Análise de desempenho de algoritmos (tempo e comparações).
• 	Criação de interfaces interativas em terminal.

🚀 Autoria
Desenvolvido por: Thiago Alves Ribeiro da Rosa
Curso: Análise e Desenvolvimento de Sistemas
Instituição: Universidade Estácio de Sá
Desafio proposto pela plataforma SAVA / GitHub Classroom


