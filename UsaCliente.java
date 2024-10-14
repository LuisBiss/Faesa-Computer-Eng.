package fila_de_atendimento;

import java.util.ArrayList;

import io.InOut;

public class UsaCliente {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Cliente> Clientes = new ArrayList<Cliente>();
		int opcao = 0;
		// menu
		do {
			opcao = InOut.leInt("1. Gerar Senha\n"
					          + "2. Atendimento\n"
					          + "3. Sair da Fila\n"
					          + "4. Mostrar Clientes Pendentes\n"
					          + "5. Sai\n"
					          + "\n Por favor, insira uma opção");
			switch (opcao) {
			case 1:
				GerarSenha(Clientes);
				break;
			case 2:
				Atendimento(Clientes);
				break;
			case 3:
				SairFila(Clientes);
				break;
			case 4:
				Imprimir(Clientes);
				break;
			case 5:
				InOut.msgDeAviso("Painel de Atendimento", "Finalizando programa...");
				break;
			default:
				System.err.println("Erro - Insira uma opção válida");
			}
		}while (opcao != 5);
	}

	private static void Imprimir(ArrayList<Cliente> clientes) {
		
	}

	private static void SairFila(ArrayList<Cliente> clientes) {
		// TODO Auto-generated method stub
		
	}

	private static void Atendimento(ArrayList<Cliente> clientes) {
		// TODO Auto-generated method stub
		
	}

	private static void GerarSenha(ArrayList<Cliente> clientes) {
		String NovoNome = InOut.leString("Qual o nome do cliente?");
		Cliente NovoCliente = new Cliente(NovoNome);
		clientes.add(NovoCliente);
		InOut.msgDeInformacao("Painel de Atendimento", "A senha do novo cliente é: " + NovoCliente.getSenhaDoCliente());
	}
}
