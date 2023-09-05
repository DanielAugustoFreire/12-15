// 1 
var resultado;
var resultado = 5 + 3 + 10 + parseInt("20");
console.log(resultado);

// 2 
var nome;
var sobrenome;
nome = prompt("Entre com o seu nome: ");
sobrenome = prompt("Entre com o seu sobrenome:");3
    document.writeln("<h3>Oi "+ nome+sobrenome,"!!</h3>");

// 3
var numero;
numero = prompt("Entre com o Numero:");
    numero = parseInt(numero);
    if(numero % 2 == 0 )
    {
        document.write("Par");
    }
    else
    {
        document.write("Impar");
    }

// 4
var operacao;
var num1;
var num2;
var somado;
operacao = prompt("Entre com a operacao:");
num1 = prompt("Entre com a num1:");
num2 = prompt("Entre com a num2:");
num1 = parseInt(num1);
num2 = parseInt(num2);

if(operacao === "+")
{
    somado = num1 + num2;
    console.log(somado);
}
else if (operacao === "-")
{
    somado = num1 - num2;
    console.log(somado);
}
else if (operacao === "*")
{
    somado = num1 * num2;
    console.log(somado);
}
else if (operacao === "/")
{
    somado = num1 / num2;
    console.log(somado);
}
else
{
    alert("Entre com uma operacao valida");
}
