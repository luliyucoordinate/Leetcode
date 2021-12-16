var romanToInt = function(s) {
    let sum = 0;
   
    for(let i = 0; i<=s.length;i++){
      switch(s[i]){//checks wether s contains any value
        case 'I':
           if(s[i+1]==="V"){
            sum += 4;
        }
        else if(s[i+1]==="X"){
          continue;
        }
        else{
          sum += 1;
        }
          break;
        case 'V':
           if(s[i-1]==="I"){
            continue;
        }
        else{
          sum += 5;
        }
            break;
        case 'X':
         if(s[i-1]==="I"){
            sum += 9;
        }
        else if(s[i+1]==="L"){
          sum += 40;
        }
        else if(s[i+1]==="C"){
          sum += 90;
        }
        else{
          sum += 10;
        }
          break;
        case 'L':
          if(s[i-1]==="X"){
            continue;
          }
          else{sum +=50;}
            
            break;
        case 'C':
          if(s[i+1]==="M"){
            sum += 900;
        }
        else if(s[i+1]==="D"){
          sum += 400;
        }
        else if(s[i-1]==="X"){
          continue;
        }
        else{
          sum += 100;
        }
          break;
        case 'D':
          if(s[i-1]==="C"){
           continue;
        }
            sum +=500;
            break;
        case 'M':
          if(s[i-1]==="C"){
            continue;
        }
        else{
       sum +=1000;
        }
        break;
      } 
    }
    return sum;
    
};
