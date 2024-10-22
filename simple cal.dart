import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const Calculator(), // Change this to point to the Calculator widget
    );
  }
}

class Calculator extends StatefulWidget {
  const Calculator({Key? key}) : super(key: key);

  @override
  State<Calculator> createState() => _CalculatorState();
}

class _CalculatorState extends State<Calculator> {
  TextEditingController controller1 = TextEditingController();
  TextEditingController controller2 = TextEditingController();
  int? num1 = 0, num2 = 0, result = 0;

  void add() {
    setState(() {
      num1 = int.parse(controller1.text);
      num2 = int.parse(controller2.text);
      result = num1! + num2!;
    });
  }

  void sub() {
    setState(() {
      num1 = int.parse(controller1.text);
      num2 = int.parse(controller2.text);
      result = num1! - num2!;
    });
  }

  void mul() {
    setState(() {
      num1 = int.parse(controller1.text);
      num2 = int.parse(controller2.text);
      result = num1! * num2!;
    });
  }

  void div() {
    setState(() {
      num1 = int.parse(controller1.text);
      num2 = int.parse(controller2.text);
      if (num2 != 0) {
        result = num1! ~/ num2!;
      } else {
        result = null; // Handle division by zero
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Cannot divide by zero')),
        );
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Simple Calculator'),
        backgroundColor: Colors.blue.shade900,
      ),
      body: Column(
        children: [
          SizedBox(height: 15),
          Text(
            'Result is: ${result ?? 'N/A'}', // Handle null case
            style: TextStyle(fontSize: 20, color: Colors.blue.shade700),
          ),
          SizedBox(height: 15),
          TextField(
            controller: controller1,
            decoration: InputDecoration(
              labelText: "Enter number",
              border:
                  OutlineInputBorder(borderRadius: BorderRadius.circular(20)),
            ),
          ),
          SizedBox(height: 15),
          TextField(
            controller: controller2,
            decoration: InputDecoration(
              labelText: "Enter number",
              border:
                  OutlineInputBorder(borderRadius: BorderRadius.circular(20)),
            ),
          ),
          SizedBox(height: 15),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              ElevatedButton(
                onPressed: () {
                  add();
                  controller1.clear();
                  controller2.clear();
                },
                child: Text('ADD'),
              ),
              ElevatedButton(
                onPressed: () {
                  sub();
                },
                child: Text('SUB'),
              ),
            ],
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              ElevatedButton(
                onPressed: () {
                  mul();
                },
                child: Text('MUL'),
              ),
              ElevatedButton(
                onPressed: () {
                  div();
                },
                child: Text('DIV'),
              ),
            ],
          )
        ],
      ),
    );
  }
}
