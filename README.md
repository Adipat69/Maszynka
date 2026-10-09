Program ten Emuluje maszynkę telefoniczną (Ringing Machine).

Generuje on za pomocą Hbridge sygnał AC o napięciu ~2Vrms który poprzez trafo TEZ 6,0d (6/230) generuje napięcie wezwania abonenta 70V ac dla 25Hz lub 20Hz (Dla starszych telefonów należy zasilić mostek oddzielnie większym napięciem by uzyskać blisko 120V).
Dzwoni on przez 2s potem 4s ciszy i ponownie. Powtarza to 4 razy a potem wraca do stanu nie wzywania.
Stan dzwonienia wyzwala sygnał Wysoki na wejściu W (W kodzie do dyspozycji można ustawić dowolny pin).
Do wykrycia czy aparat abonenta znajduje się w stanie OnHook lub OffHook stosuje się wejście H (Również w kodzie do dyspozycji) sygnał wysoki świadczy o podniesieniu słuchawki (Do wykrywania tego na linii używać przekaźnika 24V podłączonego cewką szeregowo w linii).

Projekt bazuje na rozwiązaniu Hugatry's HackVlog który oryginalnie kod napisał w C++.
Swoją wersje rozbudowałem o dodatkową funkcjonalność (Oryginał dzwonił przy zasilaniu aż do podniesienia słuchawki i wracał do dzwonienia po opuszczeniu).



Do wykorzystania w dowolnych projektach 



SCHEMAT NIEDŁUGO
