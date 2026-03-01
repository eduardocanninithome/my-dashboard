# Aplicação Simples de Login (Qt + C++)

Este projeto é uma aplicação desktop simples desenvolvida em **C++** utilizando o **framework Qt**.  
O objetivo é demonstrar um fluxo básico de autenticação com cadastro e login de usuários utilizando **MySQL remoto**.

---

## Funcionalidades

- Interface gráfica de login
- Tela de cadastro de usuário
- Validação de campos obrigatórios
- Confirmação de senha
- Criptografia básica de senha utilizando SHA-256
- Autenticação de usuário
- Acesso a área restrita após login
- Integração com banco MySQL remoto

---

## Tecnologias Utilizadas

- C++
- Qt Widgets
- Qt Designer
- Qt SQL
- MySQL
- QCryptographicHash (SHA-256)

---

## Fluxo da Aplicação

1. A aplicação inicia exibindo a tela de login.
2. O usuário pode criar uma conta através da tela de cadastro.
3. Os dados são validados antes do salvamento.
4. A senha é armazenada de forma criptografada.
5. No login, as credenciais são verificadas no banco de dados.
6. Após autenticação bem-sucedida, o usuário é direcionado para uma área restrita.

---

## Configuração do Banco MySQL Remoto

Para conexão com MySQL remoto (ex: Umbler), é necessário habilitar o driver **QMYSQL** no Qt.

---

### Configuração do arquivo `.env`

Copie o arquivo de exemplo para a pasta de build antes de executar a aplicação.

`.env.example`

Crie o arquivo 
`.env`

em

`build`

e cole o contéudo do arquivo de exemplo

### 1. Instalar MySQL Connector/C

Baixe e instale:

https://dev.mysql.com/downloads/connector/c/

Após instalar, confirme a existência do diretório:

C:\Program Files\MySQL\MySQL Connector C 6.1\

---

### 2. Instalar Qt Sources

Abra o **Qt Maintenance Tool**:

    Add or remove components → Qt → Qt 6.x → Sources
    

Finalize a instalação.

---

### 3. Compilar o Driver MySQL do Qt

Abra:


Finalize a instalação.

---

### 3. Compilar o Driver MySQL do Qt

Abra:

Execute:

```bash
cd C:\Qt\6.x\Src\qtbase\src\plugins\sqldrivers
mkdir build
cd build
````
Configure:


---

### 2. Instalar Qt Sources

Abra o **Qt Maintenance Tool**:



---

### 2. Instalar Qt Sources

Abra o **Qt Maintenance Tool**:


Add or remove components → Qt → Qt 6.x → Sources


Finalize a instalação.

---

### 3. Compilar o Driver MySQL do Qt

Abra:



Finalize a instalação.

---

### 3. Compilar o Driver MySQL do Qt

Abra:



Execute:

```bash
cd C:\Qt\6.x\Src\qtbase\src\plugins\sqldrivers
mkdir build
cd build
```

Configure:
```bash
cmake .. -G "MinGW Makefiles" ^
-DMySQL_INCLUDE_DIR="C:/Program Files/MySQL/MySQL Connector C 6.1/include" ^
-DMySQL_LIBRARY="C:/Program Files/MySQL/MySQL Connector C 6.1/lib/libmysql.lib"
```
Compile:
```bash
mingw32-make
```

### 4. Copiar o Plugin MySQL

Após a compilação, copie:

`qsqlmysql.dll`

para a pasta do executável:

`build/Desktop_Qt_6_x_MinGW_64_bit-Debug/sqldrivers/`

#### Estrutura final

```
AppLoginSample1.exe
libmysql.dll
sqldrivers/
└── qsqlmysql.dll
