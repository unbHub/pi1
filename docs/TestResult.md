# Resultados dos Testes

Este documento apresenta os resultados dos testes realizados em um robô, avaliando seu desempenho em diferentes aspectos funcionais e unitários. A tabela a seguir detalha cada teste, seu tipo, estado, o resultado esperado e o resultado obtido.

| ID  | Nome do Teste                              | Tipo       | Estado    | Resultado Esperado                                        | Resultado Obtido                                          |
|-----|-------------------------------------------|------------|-----------|----------------------------------------------------------|----------------------------------------------------------|
| T01 | Teste de Identificação do Oponente       | Funcional  | Concluído | O robô deve detectar o objeto a menos de 70 cm.        | O robô detectou o objeto no alcance de 70 cm.           |
| T02 | Teste de Perseguição                     | Funcional  | Concluído | O robô deve avançar até o objeto após a detecção.      | O robô avançou até o objeto após a detecção.            |
| T03 | Teste de Identificação da Borda          | Funcional  | Concluído | O robô deve detectar a borda da arena.                 | O robô detecta a borda corretamente.                     |
| T04 | Teste de Recuo                           | Funcional  | Concluído | O robô deve recuar ao detectar a borda da arena.       | O robô está recuando corretamente, porém, falha na identificação da borda. |
| T05 | Teste de Giro                            | Funcional  | Concluído | O robô deve girar até encontrar um objeto.             | O robô girou corretamente até encontrar o objeto.       |
| T06 | Teste de Ataque Sustentado               | Funcional  | Concluído | O robô deve empurrar o objeto para fora da arena.      | O robô empurrou o objeto para fora da arena com força constante. |
| T07 | Teste de Integração Geral                | Integração | Concluído | Todas as funções devem operar corretamente em conjunto. | Todas as funções estão integradas.                      |
| T08 | Teste do Sensor Infravermelho Esquerdo   | Unitário   | Concluído | O sensor deve identificar linhas pretas corretamente.  | O sensor identifica a linha preta em todos os testes.   |
| T09 | Teste do Sensor Infravermelho Direito    | Unitário   | Concluído | O sensor deve identificar linhas pretas corretamente.  | O sensor identifica a linha preta em todos os testes.   |
| T10 | Teste do Sensor Ultrassônico             | Unitário   | Concluído | O sensor deve identificar objetos a até 70 cm.        | O sensor está identificando objetos no alcance correto. |
| T11 | Teste do motor DC                        | Unitário   | Concluído | O motor DC deve girar proporcionalmente ao PWM.       | O motor responde corretamente, atingindo o RPM esperado. |

