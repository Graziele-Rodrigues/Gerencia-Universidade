/*
 * aluno.h
 *
 */

#ifndef ALUNO_H_
#define ALUNO_H_

#include <iostream>
#include <string>
#include "professor.h"
using namespace std;

namespace posgraduacao {

	class Aluno {

	};
}

/***********************************************/

namespace graduacao {

	class Aluno {

	private:
		int codigo;
		string nome;

		float notas[2] = {0.0, 0.0};

		static int proxCodigo;
	
	protected:
		double valorMensalidade;

	public:
		//Construtor parametrizado
		Aluno(string nome);
		//Construtor de copida
		Aluno(const Aluno &a);
		//Destrutor da classe
		~Aluno();

		//GETTERS - accessor methods
		int getCodigo();
		string getNome();
		float *getNotas();

		//SETTERS - mutator methods
		void setCodigo(int codigo);
		void setNome(string nome);
		void setNotas(float notas[]);
		float calculaMedia();

		//Funcao amiga declarada na classe Professor
		friend void Professor::alteraNotaAlunoGraduacao(Aluno &a, float n1, float n2);

		//Funcao estatica
		static int getProxCodigo();
	};

	class AlunoPesquisador : public Aluno {

	private:
		string orientador;
		string linha;
		double bolsa;

	public:
		//Construtor
		AlunoPesquisador(string nome);
		//Destrutor
		~AlunoPesquisador();

		//Getters
		double getBolsa();
		string getLinha();
		string getOrientador();

		//Setters
		void setBolsa(double bolsa);
		void setLinha(string linha);
		void setOrientador(string orientador);

		//Funcao que calcula a mensalidade do aluno pesquisador
		double calculaMensalidade(){
			return valorMensalidade - (valorMensalidade * (bolsa / 100));
		}
	};

}

#endif /* ALUNO_H_ */
