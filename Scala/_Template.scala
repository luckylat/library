object Main extends App{
  val s = io.StdIn.readLine().split(' ').map{_.toInt}

  if((s(2)-1)/s(1) < (s(0)-1)/s(3)+1){
    println("No")
  }else{
    println("Yes")
  }
}
