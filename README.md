# DBC2DBF

Este é um módulo Node.js que fornece uma interface nativa para converter arquivos DBC (arquivos DBF compactados) para o formato DBF. O módulo utiliza Node-API (N-API) para oferecer alto desempenho através de código nativo.

## Pré-requisitos

Para compilar este módulo, você precisará ter instalado:

- Node.js
- Python
- node-gyp
- Visual Studio (no Windows)

## Instalação

```
npm install dbc2dbf
```

O pacote utiliza `prebuild-install` para tentar baixar uma versão pré-compilada compatível com seu sistema. Caso não encontre uma versão pré-compilada, ele automaticamente compilará o código fonte usando node-gyp.

## Uso

```javascript
import { dbc2dbf } from 'dbc2dbf';
dbc2dbf({ input: 'caminho/arquivo/entrada.dbc', output: 'caminho/arquivo/saida.dbf' });
```

## API

### dbc2dbf(options)

Converte um arquivo DBC para DBF.

#### Parâmetros

- `options` (Object):
    - `input` (String): Caminho do arquivo DBC de entrada
    - `output` (String): Caminho onde o arquivo DBF será salvo

## Detalhes Técnicos

- Implementado como um addon nativo Node.js usando N-API
- Utiliza `prebuild` para disponibilizar binários pré-compilados
- Suporte para instalação automática de binários pré-compilados via `prebuild-install`
- Compilação nativa automática como fallback quando necessário

## Dependências

- prebuild: ^13.0.1
- node-addon-api: ^8.3.1
- prebuild-install: ^7.1.3


## Licença

```
The dbc2dbf port to NodeJS from https://github.com/danicat.
Copyright (C) 2025  Pedro Paulo Teixeira dos Santos

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
```