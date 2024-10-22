class Student {
  var stdName;
  var stdAge;
  var stdRoll_nu;

  showStdInfo() {
    print("Student Name is : ${stdName}");
    print("Student Age is : ${stdAge}");
    print("Student Roll Number is : ${stdRoll_nu}");
  }
}

void main() {
  var std = new Student();
  std.stdName = "abc";
  std.stdAge = 24;
  std.stdRoll_nu = 57498200036;

  std.showStdInfo();
}
