package fila_de_atendimento;

public class Cliente {
	
	private static int SenhaDeAtendimento;
	private static int geradorDeSenha;
	private int SenhaDoCliente;
	private String nome;
	
	public Cliente(String nome) {
		this.nome = nome;
		SenhaDoCliente = geradorDeSenha;
		geradorDeSenha++;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public static int getSenhaDeAtendimento() {
		return SenhaDeAtendimento;
	}

	public int getSenhaDoCliente() {
		return SenhaDoCliente;
	}

	@Override
	public String toString() {
		return "Cliente com nome:" + nome + ", e de senha: " + SenhaDoCliente;
	}
	
	public int proximo() {
		SenhaDeAtendimento++;
		return SenhaDeAtendimento;
	}

}
