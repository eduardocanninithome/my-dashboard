# Aplicação Simples de Login (Qt + C++)

Este projeto é uma aplicação desktop simples desenvolvida em **C++** utilizando o **framework Qt**.
O objetivo é demonstrar um fluxo básico de autenticação com cadastro e login de usuários.

## Funcionalidades

* Interface gráfica de login
* Tela de cadastro de usuário
* Validação de campos obrigatórios
* Confirmação de senha
* Criptografia básica de senha utilizando SHA-256
* Armazenamento local utilizando SQLite
* Autenticação de usuário no login
* Acesso a uma área restrita após login bem-sucedido

## Tecnologias Utilizadas

* C++
* Qt Widgets
* Qt Designer
* SQLite (Qt SQL)
* QCryptographicHash (SHA-256)

## Fluxo da Aplicação

1. A aplicação inicia exibindo a tela de login.
2. O usuário pode criar uma conta através da tela de cadastro.
3. Os dados são validados antes do salvamento.
4. A senha é armazenada de forma criptografada.
5. No login, as credenciais são verificadas no banco de dados.
6. Após autenticação bem-sucedida, o usuário é direcionado para uma área restrita.

## Objetivo do Projeto

Este projeto foi desenvolvido com fins educacionais para praticar:

* Desenvolvimento de interfaces gráficas com Qt
* Manipulação de eventos em C++
* Integração com banco de dados
* Conceitos básicos de autenticação
* Navegação entre múltiplas janelas

## Como Executar

1. Abra o projeto no **Qt Creator**.
2. Compile o projeto.
3. Execute a aplicação.
4. Cadastre um usuário e realize o login.

---

Projeto simples criado para fins de estudo e aprendizado.
