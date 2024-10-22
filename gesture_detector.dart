import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(home: MyApp()));
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key})
      : super(key: key); // Fixed class name from Mypp to MyApp

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  int numberOfTimesTapped = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Tap Counter'), // Added AppBar for better UI
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Text(
              'Tapped ' +
                  numberOfTimesTapped.toString() +
                  ' times', // Fixed spacing in the text
              style: const TextStyle(fontSize: 30),
            ),
            GestureDetector(
              onTap: () {
                setState(() {
                  numberOfTimesTapped++;
                });
              },
              child: Container(
                padding: const EdgeInsets.all(20),
                color: Colors.green[200],
                child: const Text(
                  'TAP HERE',
                  style: TextStyle(fontSize: 30),
                ),
              ), // Container
            ) // GestureDetector
          ],
        ), // Column
      ), // Center
    ); // Scaffold
  }
}
