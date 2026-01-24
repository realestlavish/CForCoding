function stringreverser(arr) {
  for (let index = 0; index < arr.length/2; index++) {
    var temp=arr[index];
    arr[index]=arr[arr.length-1-index];
    arr[arr.length-1-index]=temp;  
  }
  return arr;
}

function vowelcounter(arr) {
  var temp=0;
  for (let index = 0; index < arr.length; index++) {
    if (arr[index]== 'a' || arr[index]== 'e' || arr[index]== 'i' || arr[index]== 'o' || arr[index]== 'u'||arr[index]== 'A' || arr[index]== 'E' || arr[index]== 'I' || arr[index]== 'O' || arr[index]== 'U') {
      temp++;
    }
  }
  return temp;
}
