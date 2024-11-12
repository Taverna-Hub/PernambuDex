![pernambudex-banner](https://github.com/user-attachments/assets/6d264014-8979-4e20-bd02-93cb04b64da6)

<p align="center"><b> Pernambudex é um jogo a desenvolvido em C utilizando a biblioteca Raylib, ambientado em pontos turísticos de Pernambuco como Olinda, Boa Viagem, Cachoeira do Véu da Noiva, Pedra Furada e Feira de Caruaru.</p>

---


![GitHub repo size](https://img.shields.io/github/repo-size/Taverna-Hub/PernambuDex-temp?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/Taverna-Hub/PernambuDex-temp?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/Taverna-Hub/PernambuDex-temp?style=for-the-badge)
![Bitbucket open issues](https://img.shields.io/bitbucket/issues/Taverna-Hub/PernambuDex-temp?style=for-the-badge)
![Bitbucket open pull requests](https://img.shields.io/bitbucket/pr-raw/Taverna-Hub/PernambuDex-temp?style=for-the-badge)


## 💻 Pré-requisitos

Antes de começar, verifique se você atendeu aos seguintes requisitos:

- Você tem uma máquina `<Linux / Mac / Windows>`.
-  A versão mais recente de `<GCC / Make / Git>`

## 🚀 Instalando Penambudex

Para instalar a Pernambudex, siga estas etapas:

Linux e macOS:

1º)  Você precisará do GCC, make e git para baixar e compilar a biblioteca (Caso já tenha, ignore esse passo):
```
sudo apt install build-essential git
```

2º)  Em seguida, instale as dependencias necessárias para áudio, gráficos OpenGL e sistema de janelas X11:
```
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev
```

3º)  Baixe o código-fonte do Raylib diretamente do GitHub e entre na pasta:
```
git clone --depth 1 https://github.com/raysan5/raylib.git raylib
cd raylib/src/
```

4º)  Compile a raylib:
```
make PLATFORM=PLATFORM_DESKTOP
```

5º)  Instale a raylib:
```
sudo make install
cd ~
```

6º)  Clone o repositório do jogo:
```
git clone https://github.com/Taverna-Hub/PernambuDex-temp.git
cd PernambuDex-temp
```

7º)  Compile e rode o jogo:
```
make run
```

# windows

1º) Baixe o MSYS2:

   Acesse [msys2](https://www.msys2.org), baixe e instale o MSYS2.
  
2º) Atualize o MSYS2:
```
  pacman -Syu
```
3º) Instale o make e o compilador gcc:

```
pacman -S make mingw-w64-x86_64-gcc
```

4º) Configurar o PATH:
  
  4.1) abra:
  ```
    notepad ~/.bashrc
  ```
  4.2) adicione no final do arquivo:
  ```
    export PATH=$PATH:/mingw64/bin
  ```
  4.3) salve o arquivo:
  ```
  aperte Ctrl + S
  ```
  4.4) Aplicar as mudanças
  ```
  source ~/.bashrc
  ```
5º) instale a raylib
   ```
   pacman -S mingw-w64-x86_64-raylib

  ```
6º)  Clone o repositório do jogo:
```
git clone https://github.com/Taverna-Hub/PernambuDex-temp.git
cd PernambuDex-temp
```

7º)  Compile e rode o jogo:
```
make run
```

  


    




## 🤝 Colaboradores


<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Pandor4b">
        <img src="https://avatars.githubusercontent.com/u/142419823?v=4" width="100px;" alt="Ana Clara"/><br>
        <sub>
          <b>Ana Clara Gomes</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/deadcube04">
        <img src="https://avatars.githubusercontent.com/u/142417669?v=4" width="100px;" alt="Gabriel Albuquerque"/><br>
        <sub>
          <b>Gabriel Albuquerque</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/julsales" >
        <img src="https://avatars.githubusercontent.com/u/142419446?v=4" width="100px;" alt="Júlia Sales"/><br>
        <sub>
          <b>Júlia Sales</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Sophia-15" >
        <img src="https://avatars.githubusercontent.com/u/67246528?v=4" width="100px;" alt="Shopia Galindo"/><br>
        <sub>
          <b>Sophia Gallindo</b>
        </sub>
      </a>
    </td>
  </tr>
</table>
