# 🛡️ Construção de Territórios em C

> **Projeto acadêmico em linguagem C**
> Criação de uma base de dados simples utilizando `struct` e vetores.

---

## 📌 Visão Geral

Este programa permite o **cadastro e exibição de 5 territórios**, cada um com:

- Nome
- Cor do exército
- Quantidade de tropas

Ideal para treinar **estruturas, vetores e entrada de dados em C**.

---

## 🏗️ Estrutura do Projeto

```
main.c
├── Definição da struct Territorio
├── Cadastro dos territórios
└── Exibição dos territórios cadastrados
```

---

## 🧱 Definição da Struct

```c
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};
```

---

## 🔁 Fluxo do Programa

1️⃣ Solicita os dados dos territórios
2️⃣ Armazena em um vetor de structs
3️⃣ Exibe todas as informações cadastradas

---

## ✅ Requisitos Funcionais

- [x] Criar struct `Territorio`
- [x] Armazenar 5 territórios
- [x] Exibir dados após o cadastro

---

## 🎯 Requisitos Não Funcionais

| Critério         | Descrição                      |
| ---------------- | ------------------------------ |
| Usabilidade      | Interface clara e orientativa  |
| Desempenho       | Resposta abaixo de 2 segundos  |
| Documentação     | Código comentado               |
| Manutenibilidade | Nomes de variáveis descritivos |

---

## 🛠️ Instruções Técnicas

| Aspecto     | Orientação                      |
| ----------- | ------------------------------- |
| Strings     | `fgets()` ou `scanf("%s", ...)` |
| Inteiros    | `scanf("%d", &variavel);`       |
| Comentários | Explicar struct e laços         |

---

## 🖥️ Exemplo de Saída

```
--- Territórios Cadastrados ---
Nome: Reino do Norte
Cor: Azul
Tropas: 1500
```

---

## 📚 Conceitos Aplicados

- `struct`
- Vetores de estruturas
- Entrada e saída formatada
- Organização e documentação de código

---

💡 _Ideal para estudantes que desejam praticar manipulação de dados compostos em C._
