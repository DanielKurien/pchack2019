import React, { Component } from 'react';
import {
  StyleSheet,
  Text,
  View,
  TextInput,
  Button,
  TouchableHighlight,
  Image,
  Alert
} from 'react-native';
import { WebBrowser } from 'expo';

export default class HelloWorldApp extends Component {

  constructor(props) {
    super(props);
    state = {
      email   : '',
      password: '',
    }
  }

  onClickListener = (viewId) => {
    Alert.alert("Alert", "Button pressed "+viewId);
  }

  render() {
    
    let pic = {
      uri:'https://mir-s3-cdn-cf.behance.net/project_modules/disp/496ecb14589707.562865d064f9e.png'
       };
    let logo ={
      uri: 'http://pchacks.ca/Logos/PCHacks_2019.png'}
    return (
      
                  
      <View style={styles.container}>
      
      <Image source={logo} style={styles.logoContainer}/>
        <View style={styles.inputContainer}>
          <TextInput style={styles.inputs}
              placeholder="Email"
              keyboardType="email-address"
              underlineColorAndroid='transparent'
              onChangeText={(email) => this.setState({email})}/>
        </View>
        
        <View style={styles.inputContainer}>
          <TextInput style={styles.inputs}
              placeholder="Password"
              secureTextEntry={true}
              underlineColorAndroid='transparent'
              onChangeText={(password) => this.setState({password})}/>
        </View>

        <TouchableHighlight style={[styles.buttonContainer, styles.loginButton]} onPress={() => this.onClickListener('login')}>
          <Text style={styles.loginText}>Login</Text>
        </TouchableHighlight>
      </View>
      

    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#97B5E5',
  },
  inputContainer: {
      borderBottomColor: '#F5FCFF',
      backgroundColor: '#FFFFFF',
      borderBottomWidth: 1,
      borderRadius:10,
      width:250,
      height:45,
      marginBottom:20,
      flexDirection: 'row',
      alignItems:'center'
  },
  inputs:{
      height:45,
      marginLeft:16,
      borderBottomColor: '#FFFFFF',
      flex:1,
  },
  inputIcon:{
    width:30,
    height:30,
    marginLeft:15,
    justifyContent: 'center'
  },
  buttonContainer: {
    height:45,
    flexDirection: 'row',
    justifyContent: 'center',
    alignItems: 'center',
    marginBottom:20,
    width:250,
    borderRadius:10,
  },
  loginButton: {
    backgroundColor: "#2D5EAD",
  },
  loginText: {
    color: 'white',
  },
  backgroundContainer:{
    flex: 1,
    width:null,
    height:null,
    justifyContent: 'center'
    },
    logoContainer:{
    width: 130,
    height: 160,
    alignItems:'center',
    marginBottom: 30,
    resizeMode:'contain'
    }
});