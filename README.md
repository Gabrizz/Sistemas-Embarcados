# Sistemas-Embarcados
//LABORATÓRIO_01:

// Para 24MHz: // 1/(2410^6) = 4.166610^(-8) ns // 4.166610^(-8) * 3 instruções/loop = 125 ns // 1/(12510^(-9)) = 8*10^6 ciclos para obter intervalos de 1 segundo

// Para 120MHz: // 1/(12010^6) = 8.33310^(-9) ns // 8.33310^(-9) * 3 instruções/loop = 25 ns // 1/(2510^(-9)) = 40*10^6 ciclos para obter intervalos de 1 segundo

// Com o auxílio de um cronômetro, foi analisado o tempo total utilizado // para cada modelo realizar 10 ciclos. Na frequência de 24MHz levou // 10 segundos e na de 120MHz levou 14 segundos, nos dando uma diferença // de 4 segundos entre elas. // 24MHz completou 1 ciclo/segundo. // 120MHz completou 0.714 ciclo/segundo.
