<p>Nome: Rodrigo Estevan Nyari Vergara</p>
<p>T.I.A: 31623913</p>
<p>Turma: 5J</p>

# Vaso de plantas inteligente, Auto irrigável e Sustentável.

Projeto da matéria de Objetos inteligentes conectados para compor a nota da P2.


# Descrição:

O projeto tem como objetivo automatizar um trabalho manual, beneficiando a vida útil de suas plantas de uma forma tecnológica e econômica, podendo ser monitorado online, pode ser usado tanto para plantas alimentícias quanto para não alimentícias, o projeto pode ser usados por todos os públicos, porém o público alvo deste projeto são pessoas que não possuem muito tempo livre para regar suas plantas, e que residem em locais com pouco espaço para plantio, como apartamentos.

# Funcionamento:

O vaso de plantas inteligente é auto irrigável, após o sensor de umidade do solo posicionado próximo a planta ou semente, ele verifica se o solo está úmido ou seco, se estiver úmido o solo não é regado, se estiver seco e houver água no reservatório o solo é regado, caso o reservatório se esgote a mini bomba de água não será acionada. Os dados de solo, recipiente e bomba podem ser analisados no aplicativo mobile MQTT Dash, a placa NodeMCU envia para o broker mensagens, indicando se o solo está úmido, sendo regado, ou se o reservatório deve ser abastecido.

O código fonte encontra-se disponível na pasta Codigo_fonte_do_projeto_vaso_de_plantas_inteligente da aba Código.

# Lista de materiais usados:

<p>NodeMCU ESP8266-12</p>
<p>Sensor de Umidade do Solo Higrômetro REF: 9SS19 (foi usado no pino A0)</p>
<p>Sensor De Nível De Líquidos Sem Contato (foi usado no pino D1)</p>
<p>Mini bomba submersível 80-120l/h Dc (foi usado no pino D6)</p>
<p>Modulo Relé 1 Canal 5v (usado para acionar a mini bomba)</p>
<p>Conversor de Nível Lógico 3,3/5V (usado para o funcionamento correto do rele)</p>

# Esquema do circuíto:
<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/projeto%20iot%20-%20vaso%20inteligente.png?raw=true" alt="">

# Broker MQTT:

Foi selecionado para o projeto o broker público CloudMQTT, e também foi usado o aplicativo mobile MQTT Dash para receber as mensagens enviadas do NodeMCU ao ClouMQTT.

Foi criada uma instância no cloud mqtt:

<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/CloudMQTT%20Instance.PNG?raw=true" alt="">

E na aba detalhes contem as informações que devem ser inseridas no código para que a placa NodeMCU possa enviar as mensagem:

<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/CloudMQTT%20Detalhes.PNG?raw=true" alt="">
 Código:
<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/Conex%C3%A3o%20com%20o%20CloudMQTT%20no%20c%C3%B3digo.PNG?raw=true" alt="">

No MQTT Dash foi criado um novo dashboard chamado Vaso:

<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/MQTT%20Dash%20imagens/Dashboard.jpg" alt="">
<br><br>
O dashboard foi configaurado conforme os dados do CloudMQTT:

<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/MQTT%20Dash%20imagens/Dashboard%20config%201.jpg" alt="">

<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/MQTT%20Dash%20imagens/Dashboard%20config%202.jpg" alt="">
<br><br>
Dentro do dashboard Vaso criei um tipo Texto para aprensentar as mensagens que o NodeMCU envia para o CloudMQTT:

<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/MQTT%20Dash%20imagens/Mensagem.jpg" alt="">
<br><br>
O tipo texto é configurado com um nome a sua ecolha e com o Tópico definido na linha 25 do código fonte:

<img src="https://github.com/RodrigoEstevan/Vaso-de-plantas-inteligente/blob/master/MQTT%20Dash%20imagens/Mensagem%20config.jpg" alt="">
<br><br>
<p>Funcionamento:</p>
<p>CloudMQTT: https://www.cloudmqtt.com/</p>
<p>MQTT Dash: https://play.google.com/store/apps/details?id=net.routix.mqttdash</p>
