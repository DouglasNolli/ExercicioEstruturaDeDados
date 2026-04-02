#ifndef PONTO_H
#define PONTO_H

// declaração da struct (opaca)
typedef struct ponto Ponto;

// funções
Ponto* criar(float x, float y);
float distancia(Ponto *p1, Ponto *p2);
void destruir(Ponto *p);

#endifgit