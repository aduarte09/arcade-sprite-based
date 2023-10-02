estuda(fabricio, programacao).
estuda(joana, logica).
estuda(ana, tcc).
estuda(jose, banco).
estuda(lucas, estrutura).
estuda(nicolas, logica).
estuda(fernanda, tcc).
estuda(maria, tcc).

aluno(fabricio, ufmg).
aluno(joana, ufu).
aluno(ana, ufu).
aluno(jose, ufu).
aluno(lucas, ufmg).
aluno(nicolas, ufu).
aluno(fernanda, ufu).
aluno(maria, ufu).

professor(joao, programacao).
professor(clara, logica).
professor(roberta, tcc).
professor(antonio, banco).
professor(leandro, estrutura).

reitor(beatriz, ufmg).
reitor(marcos, ufu).

oferta(bcc, programacao).
oferta(bcc, logica).
oferta(si, tcc).
oferta(si, banco).
oferta(bcc, estrutura).

alunos_professor(X,Y):- estuda(X, Z), professor(Y, Z).

aluno_bcc(X):- oferta(bcc, Y), estuda(X, Y).

aluno_si(X):- oferta(si, Y), estuda(X, Y).

alunos_universidade(X,Y):- aluno(X, Y).

disciplinas_professor(X,Y):- professor(Y, X).

professor_universidade(X,Y):- professor(X, Z), estuda(W, Z), aluno(W, Y).

disciplinas_universidade(X,Y):- estuda(Z, X), aluno(Z, Y).

reitor_professor(X,Y):- professor_universidade(Y, Z), reitor(X, Z).
