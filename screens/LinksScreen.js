import React, { Component } from 'react';
import { NavigationActions } from "react-navigation";
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
import {createStackNavigator, createAppContainer} from 'react-navigation';

export default class LinksScreen extends Component {

  render() {
    return (
      <View style= {styles.container}>
        <Text style={{fontSize: 20, fontWeight: "bold", textAlign: 'center', marginTop: 40}}>Connected to Matthew</Text>
    
        <Button title="UPDATE, PLEASE CLICK" style={{marginTop:50}} onPress={function(){

   //Put All Your Code Here, Which You Want To Execute After Some Delay Time.
        Alert.alert("Matthew is lost, please give him a call.")

 }


}/>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 15,
    backgroundColor: '#97B5E5',
  },
});
