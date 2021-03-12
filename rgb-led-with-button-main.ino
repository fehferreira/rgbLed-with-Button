
//Declara uma variável(armazenar um valor).
int leituraBotao = 0;
int estadoLuzes = 1;

int vd = 2;
int az = 3;
int vm = 4;

int botao = 5;
int flagBotao = 0;

void setup()
{
  //Define buracos 2, 3 e 4 como saída
  pinMode(vd, OUTPUT);
  pinMode(az, OUTPUT);
  pinMode(vm, OUTPUT);
  
  //Define buraco 5 como entrada 
  pinMode(botao, INPUT);
}

//Funcao para acender vermelho
void acendeVermelho(void){
  digitalWrite(vd,LOW);
  digitalWrite(az,LOW);
  digitalWrite(vm,HIGH);
}

//Funcao para acender azul
void acendeAzul(void){
  digitalWrite(vd,LOW);
  digitalWrite(az,HIGH);
  digitalWrite(vm,LOW);
}

//Funcao para acender verde
void acendeVerde(void){
  digitalWrite(vd,HIGH);
  digitalWrite(az,LOW);
  digitalWrite(vm,LOW);
}

//Funcao para acender vermelho e azul
void acendeVermelhoEAzul(void){
  digitalWrite(vd,LOW);
  digitalWrite(az,HIGH);
  digitalWrite(vm,HIGH);
}

//Funcao para acender vermelho e verde
void acendeVermelhoEVerde(void){
  digitalWrite(vd,HIGH);
  digitalWrite(az,LOW);
  digitalWrite(vm,HIGH);
}

//Funcao para acender azul e verde
void acendeAzulEVerde(void){
  digitalWrite(vd,HIGH);
  digitalWrite(az,HIGH);
  digitalWrite(vm,LOW);
}

void testaBotao(void){
  
  //Armazeno o estado do botão(pressionado ou nao) na variável.
  leituraBotao = digitalRead(botao);
  
  
  //Teste de botão para apenas mudar o estado do LED quando 
  // soltar o botão
  
  if(leituraBotao == 1 && flagBotao == 0){
  	flagBotao = 1;
  }
  
  if(leituraBotao == 0 && flagBotao == 1){
    estadoLuzes = estadoLuzes + 1;
    flagBotao = 0;    
  }
}

void incrementaAutomaticamente(){
  estadoLuzes = estadoLuzes + 1;
  delay(1000);
}

void loop()
{  

  //Chama uma função de mudança de cor automática
  incrementaAutomaticamente();
  
  //testa o estadoLuzes para o valor que ele armazenar
  switch(estadoLuzes){
    
    //Se estadoLuzes for igual a 1, acende VERMELHO
  	case 1:
    	acendeVermelho();
    	break;
  	
    //Se estadoLuzes for igual a 2, acende AZUL
    case 2:
    	acendeAzul();
    	break;
          
    //se estadoLuzes for igual a 3, acende VERDE
    case 3:
    	acendeVerde();
    	break;
    
    //se estadoLuzes for igual a 4, acende VERMELHO e AZUL
    case 4:
    	acendeVermelhoEAzul();
    	break;
    
    //se estadoLuzes for igual a 5, acende VERMELHO e VERDE
    case 5:
    	acendeVermelhoEVerde();
    	break;
    
    //se estadoLuzes for igual a 6, acende AZUL e VERDE
    case 6:
    	acendeAzulEVerde();
    	break;
    
    //se nao for nenhuma das oções acima, estadoLuzes volta a 0
    default:
    	estadoLuzes = 1;
    	break;
  }
  
}








