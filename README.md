# Sistema Embarcado para Carrinho Sumô 🤖

## Introdução 📝

Este projeto consiste no desenvolvimento de um sistema embarcado para um robô sumô, implementado por um grupo multidisciplinar. O sistema foi dividido em quatro categorias: **software, hardware, energia e estrutura**. Este documento foca na equipe responsável pelo **software**, detalhando seus membros e a documentação produzida.

### O que é um Sistema Embarcado? 🔧

Um sistema embarcado é um sistema computacional dedicado a uma função específica dentro de um dispositivo maior. Ele geralmente combina hardware e software otimizados para tarefas particulares, oferecendo eficiência e confiabilidade. No contexto deste projeto, o sistema embarcado foi desenvolvido para controlar o carrinho sumô, garantindo que ele detectasse e reagisse adequadamente a obstáculos e limites da arena.

## Descrição do Software 🖥️

O software implementado no robô é articulado pelo **Arduino Nano**. A estratégia consiste no uso de **dois sensores infravermelhos** e **um sensor de ultrassom** para orientar o robô na arena.

1. 🤖 O robô inicia no centro da pista, com os motores girando em sentidos opostos, permitindo que ele rotacione.
2. 🎯 O sensor de ultrassom detecta objetos à sua frente.
3. 🚀 Quando um objeto é detectado, o robô se move em linha reta na direção do alvo.
4. ⚠️ Caso os sensores infravermelhos detectem a borda da arena (linha preta), o software:
   - 🔲 Reconhece a linha preta devido à ausência de reflexão.
   - 🔄 Gira o robô em 180°.
   - ➡️ Move-se em linha reta equivalente ao raio da pista.
   - 🔁 Reinicia o processo, garantindo que todos os objetos sejam retirados da arena.

## Membros da Equipe de Software 👨‍💻

| Nome | Matrícula |
|------|----------|
| Diego Carlito Rodrigues de Souza | 221007690 |
| Jonas Silva Alencar | 221022346 |
| Lucas Carminati | 190112000 |
| Luiz Gustavo Silva de Almeida | 221022669 |
| Marcos Antonio Teles de Castilhos | 221008300 |
| Matheus Do Vale Lameira | 202070064 |
| Micael Nildo Oliveira Souza | 222031626 |

## Documentação do Sistema 📂

A equipe de software produziu uma documentação detalhada do sistema desenvolvido, incluindo:

- 📌 **Diagrama de Classes**: Representação das classes utilizadas no software e seus relacionamentos.
- 📌 **Diagrama de Casos de Uso**: Demonstração das interações entre o usuário e o sistema.
- 📌 **Diagrama BPMN**: Fluxo de funcionamento do software dentro do processo operacional.
- 📌 **Arquitetura do Software**: Estrutura organizacional do software, mostrando os principais componentes e suas interações.
- 📌 **Backlog**: Lista de funcionalidades planejadas e desenvolvidas.
- 📌 **Requisitos Não Funcionais**: Restrições e atributos de qualidade do sistema.
- 📌 **Roteiro de Testes**: Estratégia e critérios para validação do software.

## Conclusão

O software desenvolvido para o carrinho sumô utiliza sensores para detectar obstáculos e bordas da arena, implementando uma estratégia eficiente para remover oponentes. A equipe de software foi responsável por toda a lógica de controle e documentação do sistema, garantindo um desenvolvimento organizado e funcional.

## Licença 📜
Este projeto está licenciado sob a **Licença MIT** - veja o arquivo [LICENSE](LICENSE) para mais detalhes.
